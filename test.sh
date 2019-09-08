#!/usr/bin/env bash

# add provider
cleos push action identity provider '["myprovider", "Light KYC Provider Metadata"]' -p identity

# add tier
cleos push action identity tier '[1, "standard", "Standard Tier for light KYC"]' -p identity

# add/remove identity using provider
cleos push action identity add '["myprovider", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "remove me"]' -p myprovider
cleos push action identity remove '["myprovider", "myaccount"]' -p myprovider
cleos push action identity add '["myprovider", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "Additional Metadata for Light KYC"]' -p myprovider
