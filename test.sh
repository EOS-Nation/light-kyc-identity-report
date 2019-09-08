#!/usr/bin/env bash

# add provider
cleos push action identity provider '["transit", "FAST Transit"]' -p identity

# add tier
cleos push action identity tier '[1, "eth", "ETH identity"]' -p identity

# add/remove identity using provider
cleos push action identity add '["transit", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "remove me"]' -p transit
cleos push action identity remove '["transit", "myaccount"]' -p transit
cleos push action identity add '["transit", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "0x04136750a3df9f3cd19e06f60af25f596c74aa0c"]' -p transit

# errors
cleos push action identity add '["myaccount", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "provider is not authorized"]' -p myaccount
cleos push action identity tier '[1, "standard", "missing authority of identity"]' -p myaccount
cleos push action identity provider '["myaccount", "missing authority of identity"]' -p myaccount
cleos push action identity provider '["myaccount", "missing authority of identity"]' -p transit
cleos push action identity add '["transit", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 9, "tier does not exist"]' -p transit
