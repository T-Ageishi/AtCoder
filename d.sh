#!/bin/bash
#テストケースのダウンロード

rm -rf ./test

if [$1 == ""]; then
  read -p "URLを入力してください: " url
  oj d ${url}
else
  oj d $1
fi
