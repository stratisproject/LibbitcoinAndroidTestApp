#include <jni.h>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <bitcoin/system.hpp>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_staticlibraryplayground_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {



    return env->NewStringUTF(address.c_str());
}

std::string getAddress() {
    std::vector<std::string> words{
        "legal", "door", "leopard", "fire",
        "attract", "stove", "similar", "response",
        "photo", "prize", "seminar", "frown"};

    libbitcoin::system::long_hash wallet_generation_seed(
            libbitcoin::system::wallet::decode_mnemonic(words));

    libbitcoin::system::data_chunk seed(std::begin(wallet_generation_seed),
                                        std::end(wallet_generation_seed));

    libbitcoin::system::wallet::hd_private privateKey_(seed);
    libbitcoin::system::wallet::ec_public ecPublicKey_(privateKey_);

    return ecPublicKey_.to_payment_address(/*version*/ 127).encoded();
}