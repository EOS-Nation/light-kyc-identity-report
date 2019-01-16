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
$ cleos push action <contract> <action> [data] -p <account>@active
```

## Tables

**accounts*

| variable  | type    | description        |
|-----------|---------|--------------------|
| account   | account | EOSIO Account Name |
| score     | integer | Token Weighted Score     |
| metadata  | JSON    | Token Forensics Metadata |
| timestamp | datetime| Last updated             |
