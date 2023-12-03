#!/bin/bash
#テストケースのダウンロード

url = "";

if [$1 == ""]; then
  read -p "URLを入力してください: " url
else
  url = $1
fi


rm -rf ./test
oj d ${url}
