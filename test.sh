#!/usr/bin/env bash

# add provider
cleos push action identity provider '["myprovider", "Provider Metadata"]' -p identity

# add tier
cleos push action identity tier '[1, "standard", "Standard Tier"]' -p identity

# add/remove identity using provider
cleos push action identity add '["myprovider", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "remove me"]' -p myprovider
cleos push action identity remove '["myprovider", "myaccount"]' -p myprovider
cleos push action identity add '["myprovider", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "Additional Metadata"]' -p myprovider

# errors
cleos push action identity add '["myaccount", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "provider is not authorized"]' -p myaccount
cleos push action identity tier '[1, "standard", "missing authority of identity"]' -p myaccount
cleos push action identity provider '["myaccount", "missing authority of identity"]' -p myaccount
cleos push action identity provider '["myaccount", "missing authority of identity"]' -p myprovider
cleos push action identity add '["myprovider", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 9, "tier does not exist"]' -p myprovider
