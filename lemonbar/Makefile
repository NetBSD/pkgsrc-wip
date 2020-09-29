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

USE_TOOLS+=	gmake

# this post-build target was copied from the FreeBSD port.
#
# this generates the man page because, for some reason, the `all'
# target of lemonbar's Makefile does not call the `doc' target
# that would normally do this.
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
