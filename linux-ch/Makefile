# $NetBSD: Makefile,v 1.5 2005/07/27 16:26:20 thomasklausner Exp $

DISTNAME=	chstandard-4.0.0.linux2.2.5.intel
PKGNAME=	linux-ch-4.0.0
CATEGORIES=	devel
MASTER_SITES=	http://www.softintegration.com/download/software/release/Linux/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.softintegration.com/products/
COMMENT=	Ch is an interactive C development environment

# I have included chstandard-license for pkgsrc-wip purposes as
# linux-ch/licenses/chstandard-license. Basically,
# this tool is free for personal and commercial use.

LICENSE=		chstandard-license

LINUX_BINPKG_FMT=	plain
LINUX_USE_X11=		yes

do-install:
	cd ${WRKSRC} && ${SETENV} PREFIX="${EMULOPTDIR}" ./install.sh
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${EMULOPTDIR} && ${FIND} ch4.0.0 -type f | \
		${SED} -e "s|^|\$${EMULOPTSUBDIR}/|" >> ${PLIST_SRC}
	cd ${EMULOPTDIR} && ${FIND} ch4.0.0 -type l | \
		${SED} -e "s|^|\$${EMULOPTSUBDIR}/|" >> ${PLIST_SRC}
	cd ${EMULOPTDIR} && ${FIND} -d ch4.0.0  -type d  | \
	${SED} -e "s/^/@dirrm \$${EMULOPTSUBDIR}\//" >>${PLIST_SRC}

.include "../../wip/mk/linuxbin.pkg.mk"
.include "../../mk/bsd.pkg.mk"
