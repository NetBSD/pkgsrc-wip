# $NetBSD: Makefile,v 1.14 2012/10/03 09:10:41 asau Exp $

DISTNAME=	chprofessional-4.0.0.linux2.2.5.intel
PKGNAME=	linux-chprofessional-4.0.0
CATEGORIES=	devel
MASTER_SITES=	http://www.softintegration.com/download/software/release/Linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.softintegration.com/products/chprofessional/
COMMENT=	Ch is an interactive C development environment
#
# I have included chpro-license for pkgsrc-wip purposes as
# linux-chprofessional/licenses/chpro-license. Basically,
# this tool is free for academic purposes *only*. For personal
# or commercial use, go for Ch standard edition
#
LICENSE=	chpro-license


BUILD_DIRS=	# empty

#
# Webpage claims, that there are ports for Solaris, HP-UX, MacOS
# and Windows. Unfortunatley, I can't test on those, so until someone
# does this... :
#

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat x11

do-install:
	cd ${WRKSRC} && ${SETENV} PREFIX="${PREFIX}" ./install.sh
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${PREFIX} && ${FIND} chprofessional4.0.0 -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} chprofessional4.0.0 -type l -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
