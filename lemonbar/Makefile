# $NetBSD$

DISTNAME=	lemonbar-1.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=LemonBoy/}
GITHUB_PROJECT=	bar
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	hopkinsza@gmail.com
HOMEPAGE=	https://github.com/LemonBoy/bar
COMMENT=	Featherweight lemon-scented bar
LICENSE=	mit

# perl is a build dependency because pod2man is needed
# to generate lemonbar's man page
USE_TOOLS+=	gmake perl

# generate the man page as in the lemonbar Makefile's `doc' target
# because, for some reason, `all' does not call it
post-build:
	${LOCALBASE}/bin/pod2man --section=1 --name=lemonbar \
		--center="lemonbar manual" \
		--release="${PKGVERSION_NOREV}" \
		${WRKSRC}/README.pod > ${WRKSRC}/lemonbar.1

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/lemonbar ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/lemonbar.1 ${DESTDIR}${PREFIX}/man/man1/

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
