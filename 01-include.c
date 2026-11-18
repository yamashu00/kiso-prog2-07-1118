// ==================================================
// 【種類】確認（プリプロセスの結果を見る）
//
// 【目的】
//   #include は「指定したファイルの中身を、その行の場所にそのまま貼り付ける（コピー＆ペーストする）」
//   命令であることを、自分の目で確かめる
//
// 【登場するファイル】
//   ・01-include.c …… 材料（このファイル）。main の中で hello() を呼んでいるが、hello の中身は書いていない
//   ・sample.txt ……… 材料（最初から配布）。hello 関数だけが書いてある部品。main は無い
//   ・01-include.i …… 結果（手順2で自分で作る）。#include を貼り付けたあとの姿を保存したもの
//                       → 中身を見て確かめるためだけのファイル。編集しない・#include しない
//
//   材料（01-include.c ＋ sample.txt）──gcc -E──▶ 結果（01-include.i）
//
// 【手順】
//   1. ターミナルで ls を実行し、01-include.c と sample.txt が同じフォルダにあることを確かめる
//   2. gcc -E 01-include.c -o 01-include.i を実行する
//        ・-E は「#include などの貼り付けだけを行って、そこで止める」オプション
//        ・-o 01-include.i は「その結果を 01-include.i という名前のファイルに保存する」という意味
//   3. tail -n 12 01-include.i を実行する（01-include.i の最後の12行だけを画面に表示する）
//   4. 表示された中に、sample.txt の中身（void hello(void) { … }）と、このファイルの main が
//      上下に並んでいることを確かめる
//        → #include "sample.txt" と書いた行が、sample.txt の中身に置き換わっている
//        ・「# 」で始まる行は gcc が付けた目印なので、気にしなくてよい
//   5. gcc 01-include.c -o 01-include を実行する（-E を付けないので、4つの工程を最後まで実行して、実行ファイルを作る）
//   6. ./01-include を実行し、「Hello」と表示されることを確かめる
//        → このファイルに hello の中身を書いていないのに動くのは、sample.txt の中身が貼り付けられたから
//
// 【確認できたらOK】
//   ・手順4で、#include を書いた場所に sample.txt の中身が入っていた ⭕️
//   ・手順6で、「Hello」と表示された ⭕️
//
// 【やってみよう】
//   ① #include "sample.txt" の行を消して、手順5をもう一度実行する。どんなエラーが出る？ なぜ？
/* 01-include.c:44:5: error: call to undeclared function 'hello'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
   44 |     hello();
      |     ^ 
    理由：#include "sample.txt" を削除すると、sample.txt に記述された hello() 関数が読み込まれなくなる。その結果、コンパイラが hello() 関数の宣言を認識できず、エラーが発生した。*/
//   ② wc -l 01-include.i を実行して、01-include.i の行数を数える。：580行
//      このファイルは十数行なのに、なぜ数百行もある？（ヒント：#include <stdio.h> も同じように貼り付けられる）
// ==================================================
#include <stdio.h>
//#include "sample.txt"

int main(void)
{
    hello();
    return 0;
}
