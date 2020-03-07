/*
 * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * Additions Copyright 2016 Espressif Systems (Shanghai) PTE LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * @file aws_iot_certifcates.c
 * @brief File to store the AWS certificates in the form of arrays
 */

#ifdef __cplusplus
extern "C" {
#endif

const char aws_root_ca_pem[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n\
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\n\
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\n\
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\n\
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\n\
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n\
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\n\
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\n\
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\n\
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\n\
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\n\
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\n\
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\n\
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\n\
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\n\
****************************************************************\n\
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\n\
rqXRfboQnoZsG4q5WTP468SQvvG5\n\
-----END CERTIFICATE-----\n"};

const char certificate_pem_crt[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDWTCCAkGgAwIBAgIUWxxS4xnnzBXoaoxwgWQ9Ij7ikKswDQYJKoZIhvcNAQEL\n\
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g\n\
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTE5MDgyNzAyNTgw\n\
MloXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0\n\
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBANuqreF2QrZVEiM9WnLM\n\
olxyZqghBJFwaemLkFHk+MCIoaq9sJkVLEGYD2hibZoXdCfY/RfuHH+iT4J60Fq0\n\
zBc+lmI8TthoUFQaD+Igz3Y9xX2S0ybcPa9M3wY4nqr21AoMXc2CnU2mOZoTMwRj\n\
tSOeRMn0x1d9c4gdQhDPiXcqbaqMmBVCL62ZXD3+Lxl6Uk2ueDwxsfGhNZhqomqn\n\
0YMfS1Tt9Gucxzitem1H515CTuCQI+FVHS+w5biDrByKXkN7lf2vTe0HWXTu+UG3\n\
BUNFSKO6t7jiqn/aHsrX4cTBFVT3Q5PsUWil50CD7otErNbBaTp6vfYgUOzxHIqb\n\
8dMCAwEAAaNgMF4wHwYDVR0jBBgwFoAULk4x7lpoFeUUJpGEQh5GbgXq1LIwHQYD\n\
VR0OBBYEFIFXIlis8lVqLCZ/MbJb0n3CKKN/MAwGA1UdEwEB/wQCMAAwDgYDVR0P\n\
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQC28NIcq7UVhalGfkAAqpDj24zm\n\
cmtg1UiAE/lEKXz+/9gb6eGaHsceqg8pRPNe8sb1qHHxztUp5tms0igTdDyRd2x6\n\
Ogi/E4DCLZMUnOZ8vUHZbE3VMQAr2ntBiSYb3kwGoaCB8FVZeshfc1Rp+l5ZZG2M\n\
k6KXulEOvCaLGl0achNNx+lJgEG2HsbgxPgxErgxa4X8gJt/aO2N/5/arV9j78/G\n\
****************************************************************\n\
f/PfLLua47hqTc/+z+PL0jA/xT1qnG2BXBb6yMIJTmcViojhVFzxkRCfHE3R\n\
-----END CERTIFICATE-----\n"};

const char private_pem_key[] = {"-----BEGIN RSA PRIVATE KEY-----\n\
MIIEogIBAAKCAQEA26qt4XZCtlUSIz1acsyiXHJmqCEEkXBp6YuQUeT4wIihqr2w\n\
mRUsQZgPaGJtmhd0J9j9F+4cf6JPgnrQWrTMFz6WYjxO2GhQVBoP4iDPdj3FfZLT\n\
Jtw9r0zfBjieqvbUCgxdzYKdTaY5mhMzBGO1I55EyfTHV31ziB1CEM+JdyptqoyY\n\
FUIvrZlcPf4vGXpSTa54PDGx8aE1mGqiaqfRgx9LVO30a5zHOK16bUfnXkJO4JAj\n\
4VUdL7DluIOsHIpeQ3uV/a9N7QdZdO75QbcFQ0VIo7q3uOKqf9oeytfhxMEVVPdD\n\
k+xRaKXnQIPui0Ss1sFpOnq99iBQ7PEcipvx0wIDAQABAoIBAE0vZ/G1EDPpKHph\n\
cIquBM7fE9s33tcL3OtHMurTveRJHiVUid0AZ5CU0bUoAMMIQrRNtoDWFgVzDuUW\n\
Kmf051GzmDvkXQAFh1RF5Bbc2Ij/o4lAMhmRgcs7A5K4CmigWlk9hyhTINrL8amF\n\
3YNJVbiyQBGGhRTk69eEEFa/1dmc1DopDXLgRAkOhAYVBKU4vxyILikQPe/YCVp+\n\
tW2LdkireCbahryVnxKrdiCAj3ijWrtNxX6Y23YCHXN8iTdtmSVnXMmXpPGy0lXv\n\
9kFHBoSdhQfARK5nYJf6NNZDbXe50AvVERbuFJY5vtFB6TTUGwCAm/m/E6YFSydA\n\
VJE7i2ECgYEA9Fiwl9Lx0VD17rs1vGGyMZKjkoS6g8K/oK+0WLX5UYk5EDQte8qc\n\
WKbGR8se7BT7KDIvPBMj/BitnEMwGc+lexB90Ko+OuSK7B7gnBmvIiMtsfXsD2Ht\n\
3RsJ3oWP8nJZSbME7H0k0b2DWbDKUwDxEVAb9Mfa1/HSd6AepEBz1mcCgYEA5iSq\n\
g05NFxDK8o0h4vlEXdwAPVk2RNDxk6LDikUaPy92m6+NUNcdYlaOHs0hYL98YsWV\n\
xMLINRGGmxVBHA+4R7UCSDpbb1U9XyR+YCqYf4Wce+UzD4TvY29G1kySHBw1GtsH\n\
2i30xag3+Yoz9H1T1O1IKBIYkW1e3estUbgI7bUCgYBVKdxS7mjuJaOyE3oFMJ/k\n\
+1Ebrjs71VLo9JSNHs/JBWToKud3cATSOT5+o2MhsaZgOi2QaLNwGEHaZuiK9n6c\n\
yACyC8QozqNE7PYoMiOCaHRyxF4EdoNrPxNPhYnIXOaV81lR+8QrfjwbtKywBXIA\n\
MMWtqUKzZUuP+jTz1qsJHQKBgADXwYgZkU60UQnyWl1qbEWruJSA7yHxYfEYd37a\n\
Ie55TgXj7rCNGR5zErIqLiUcjmgOMS43SGRpXATVXxerNxGMKCX7kLonpcHjcFMJ\n\
1OUiqCAMBtPXuMi0b535Sc+wisE+bBjwciUHKK1RRD9w9g2hkNIUvuJJdD97zP6v\n\
****************************************************************\n\
S5Bui03/nL/qjdGSzBftBk5YMrpoQWN7LrO7FcEdPAmbQpWncxC+XimSzkLfEJay\n\
I55oDblWvn60CI+hiceyOuvEhRYd+PNvjZSmCYz9sm3W8OoX6AE=\n\
-----END RSA PRIVATE KEY-----\n"};


#ifdef __cplusplus
}
#endif
