pkgname=c-interattivo
pkgver=1.1
pkgrel=2
arch=('x86_64')
pkgdesc="Programma C interattivo con menu (ISO C90)"
url="https://github.com/jacklapinza/C-interattivo"
license=('custom')
depends=('ncurses')
makedepends=('git' 'gcc')

source=("git+https://github.com/jacklapinza/C-interattivo.git")
md5sums=('SKIP')


build() {
    cd "$srcdir/C-interattivo/src"

    # Find all .c files
    sources=$(find . -name '*.c')

    # Find all unique directories containing .h files
    header_dirs=$(find ./headers -type f -name '*.h' -exec dirname {} \; | sort -u)

    # Build -I flags for each header dir
    includes=$(printf -- "-I%s " $header_dirs)

    gcc -Wall -std=c90 -D_POSIX_C_SOURCE=199309L \
        $includes \
        -o "$pkgname" \
        $sources \
        -lncurses
}

package() {
    install -Dm755 "$srcdir/C-interattivo/src/$pkgname" "$pkgdir/usr/bin/$pkgname"
    install -Dm644 "$srcdir/C-interattivo/src/text/benvenuti.txt" "$pkgdir/usr/share/$pkgname/benvenuti.txt"
}

