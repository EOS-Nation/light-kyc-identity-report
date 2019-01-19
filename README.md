# EOS Detective Reports

> EOSIO based smart contract that publishes token forensic reports on chain.

## How to Install

## How to Use

Get Account Data

```
$ cleos get table <contract> <scope> accounts
```

Push new report

```
$ cleos push action <contract> post '["account",score,"metadata"]' -p <account>@active
```

Update report

```
$ cleos push action <contract> post '["account",score,"metadata"]' -p <account>@active
```

Remove report before expiry

```
$ cleos push action <contract> post '["account",0,""]' -p <account>@active
```

Remove report after expiry

```
$ cleos push action <contract> expire '["account"]' -p <account>@active
```

## Tables

**accounts**

| variable  | type    | description        |
|-----------|---------|--------------------|
| account   | account | EOSIO Account Name |
| score     | integer | Token Weighted Score     |
| metadata  | JSON    | Token Forensics Metadata |
| timestamp | datetime| Last updated             |
