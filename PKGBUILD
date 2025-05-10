pkgname=c-interattivo
pkgver=1.0
pkgrel=1
arch=('x86_64')
pkgdesc="Programma C interattivo con menu (ISO C90)"
url="https://github.com/jacklapinza/C-interattivo"
license=('custom')
depends=('ncurses')
makedepends=('gcc')

# Update this to fetch the package directly from your GitHub release
source=(
    "https://github.com/jacklapinza/C-interattivo/releases/download/v${pkgver}/c-interattivo-${pkgver}-x86_64.pkg.tar.zst"
)

md5sums=('SKIP')

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

