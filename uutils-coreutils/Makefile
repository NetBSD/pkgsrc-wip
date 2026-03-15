# $NetBSD$

DISTNAME=	coreutils-0.7.0
PKGNAME=	uutils-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=uutils/}
GITHUB_PROJECT=	coreutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uutils.github.io/coreutils/
COMMENT=	Cross-platform Rust rewrite of the GNU coreutils
LICENSE=	mit

RUST_REQ=	1.88.0

PROGS+=		base32 base64 basename basenc cat cksum b2sum md5sum sha1sum sha224sum sha256sum \
		sha384sum sha512sum comm cp csplit cut date dd df dir dircolors dirname du echo \
		env expand expr factor false fmt fold head join link ln ls mkdir mktemp more mv nl \
		numfmt od paste pr printenv printf ptx pwd readlink realpath rm rmdir seq shred \
		shuf sleep sort split sum tac tail tee test touch tr true truncate tsort unexpand \
		uniq unlink vdir wc yes

INSTALLATION_DIRS+=	uutils-coreutils/bin

post-install:
.for program in ${PROGS}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} coreutils uu-${program}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} coreutils ../uutils-coreutils/bin/${program}
.endfor

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
