# $NetBSD: Makefile,v 1.1.1.1 2003/11/08 02:05:34 mpasternak Exp $

DISTNAME=	chstandard-4.0.0.linux2.2.5.intel
PKGNAME=	linux-ch-4.0.0
CATEGORIES=	devel
MASTER_SITES=	http://www.softintegration.com/download/software/release/Linux/

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://www.softintegration.com/products/
COMMENT=	Ch is an interactive C development environment

NO_BUILD=	# defined

#
# I have included chstandard-license for pkgsrc-wip purposes as
# linux-ch/licenses/chstandard-license. Basically,
# this tool is free for personal and commercial use.
#

LICENSE=	chstandard-license

#
# Webpage claims, that there are ports for Solaris, HP-UX, MacOS
# and Windows. Unfortunatley, I can't test on those, so until someone
# does this... :
# 

ONLY_FOR_PLATFORM=	*-i386

do-install:
	cd ${WRKSRC} && ${SETENV} PREFIX="${PREFIX}" ./install.sh
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${PREFIX} && ${FIND} ch4.0.0 -type f -type l -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ch4.0.0  -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	suse_compat-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_x11-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

.include "../../mk/bsd.pkg.mk"
