pkgname=c-interattivo
pkgver=1.0
pkgrel=1
arch=('x86_64')
pkgdesc="Programma C interattivo con menu (ISO C90)"
url="https://esempio.org"
license=('custom')
depends=('ncurses')
makedepends=('gcc')
source=(
    'main.c'
    'benvenuti.c'
    'menu_principale.c'
    'menu_esercizi_vettori.c'
    'menu_vettori_matrici.c'
    'utils.c'
    'benvenuti.txt'
    'funzioni.h'
    'menu_principale.h'
    'menu_esercizi_vettori.h'
    'menu_vettori_matrici.h'
    'sub_menu.h'
    'utils.h'
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

