pkgname=C-interattivo
pkgver=1.0
pkgrel=1
arch=('x86_64')
...

source=(
    "src/main.c"
    "src/benvenuti.c"
    "src/menu_principale.c"
    "src/menu_esercizi_vettori.c"
    "src/menu_vettori_matrici.c"
    "src/utils.c"
    "src/funzioni.h"
    "src/menu_principale.h"
    "src/menu_esercizi_vettori.h"
    "src/menu_vettori_matrici.h"
    "src/sub_menu.h"
    "src/utils.h"
    "benvenuti.txt"
)

md5sums=('SKIP' 'SKIP' 'SKIP' 'SKIP' 'SKIP' 'SKIP' 'SKIP' 'SKIP' 'SKIP' 'SKIP' 'SKIP' 'SKIP' 'SKIP')

build() {
    cd "$srcdir"
    gcc -Wall -std=c90 -D_POSIX_C_SOURCE=199309L \
        -o "$pkgname" \
        main.c benvenuti.c menu_principale.c menu_esercizi_vettori.c \
        menu_vettori_matrici.c utils.c \
        -lncurses
}

package() {
    install -Dm755 "$srcdir/$pkgname" "$pkgdir/usr/bin/$pkgname"
    install -Dm644 "$srcdir/benvenuti.txt" "$pkgdir/usr/share/$pkgname/benvenuti.txt"
}

