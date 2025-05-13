pkgname=c-interattivo
pkgver=1.0
pkgrel=1
arch=('x86_64')
pkgdesc="Programma C interattivo con menu (ISO C90)"
url="https://esempio.org"
license=('custom')
depends=('ncurses')
makedepends=('git' 'gcc')

source=("git+https://github.com/jacklapinza/C-interattivo.git")
md5sums=('SKIP')

# build() {
#     cd "$srcdir/C-interattivo/src/source"
#
#     gcc -Wall -std=c90 -D_POSIX_C_SOURCE=199309L \
#         -I"$srcdir/C-interattivo/src/headers" \
#         -o "$pkgname" \
#         main.c benvenuti.c menu_principale.c menu_esercizi_vettori.c \
#         menu_vettori_matrici.c utils.c \
#         -lncurses
# }
#

build() {
    cd "$srcdir/C-interattivo/src"

    # Find all .c files in src and subdirectories
    sources=$(find . -name '*.c')

    gcc -Wall -std=c90 -D_POSIX_C_SOURCE=199309L \
        -I"./headers" \
        -o "$pkgname" \
        $sources \
        -lncurses
}


# package() {
#     install -Dm755 "$srcdir/C-interattivo/src/source/$pkgname" "$pkgdir/usr/bin/$pkgname"
#     install -Dm644 "$srcdir/C-interattivo/src/text/benvenuti.txt" "$pkgdir/usr/share/$pkgname/benvenuti.txt"
# }

package() {
    install -Dm755 "$srcdir/C-interattivo/src/$pkgname" "$pkgdir/usr/bin/$pkgname"
    install -Dm644 "$srcdir/C-interattivo/src/text/benvenuti.txt" "$pkgdir/usr/share/$pkgname/benvenuti.txt"
}

