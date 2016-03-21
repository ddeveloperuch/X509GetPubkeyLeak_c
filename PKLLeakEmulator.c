//
//  PKLLeakEmulator.m
//  X509GetPubkeyLeak
//
//  Created by Developer on 3/21/16.
//  Copyright (c) 2016 Developer. All rights reserved.
//
// ********************************************************************************************************************************************************** //

#include "PKLLeakEmulator.h"
#include "PKLX509Certificate.h"

// ********************************************************************************************************************************************************** //

void start_leak_emulation(void)
{
    X509 *X509Certificate = NULL;
    EVP_PKEY *orig_pkey = NULL;
    
    X509Certificate = PKLGenerateTestX509Certificate(NID_X9_62_prime256v1);
    orig_pkey = X509_get_pubkey(X509Certificate);
    
    EVP_PKEY_free(orig_pkey);
    X509_free(X509Certificate );
}

