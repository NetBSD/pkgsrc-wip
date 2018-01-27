# $NetBSD: Makefile,v 1.9 2012/10/03 09:10:41 asau Exp $

DISTNAME=	chstandard-4.0.0.linux2.2.5.intel
PKGNAME=	linux-ch-4.0.0
CATEGORIES=	devel
MASTER_SITES=	http://www.softintegration.com/download/software/release/Linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.softintegration.com/products/
COMMENT=	Ch is an interactive C development environment
# I have included chstandard-license for pkgsrc-wip purposes as
# linux-ch/licenses/chstandard-license. Basically,
# this tool is free for personal and commercial use.
LICENSE=	chstandard-license

LINUX_BINPKG_FMT=	plain
LINUX_USE_X11=		yes


do-install:
	cd ${WRKSRC} && ${SETENV} PREFIX="${EMULOPTDIR}" ./install.sh
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${EMULOPTDIR} && ${FIND} ch4.0.0 -type f | \
		${SED} -e "s|^|\$${EMULOPTSUBDIR}/|" >> ${PLIST_SRC}
	cd ${EMULOPTDIR} && ${FIND} ch4.0.0 -type l | \
		${SED} -e "s|^|\$${EMULOPTSUBDIR}/|" >> ${PLIST_SRC}

.include "../../wip/mk/linuxbin.pkg.mk"
.include "../../mk/bsd.pkg.mk"
