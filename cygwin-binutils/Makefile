# $NetBSD: Makefile,v 1.2 2010/10/14 03:53:53 makoto Exp $
# $Id: Makefile,v 1.2 2010/10/14 03:53:53 makoto Exp $

DISTNAME=	binutils-2.20
PKGNAME=	cygwin-${DISTNAME:S/-src//}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

#PATCH_SITES=    ${MASTER_SITE_GNU:=binutils/}      
#PATCHFILES=     binutils-2.20-2.20.1-patch.gz
#PATCH_DIST_STRIP=       -p1

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://www.cygwin.com/
COMMENT=	GNU binutils ported to Win32/Cygwin environment

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_TOOLS+=		pax
INFO_FILES=		yes

post-install:
.for f in windres dllwrap
	${LN} -fs ${PREFIX}/bin/${CYGWIN_TARGET}-${f} \
                ${DESTDIR}${PREFIX}/${CYGWIN_TARGET}/bin/${f}
.endfor

.include "../../wip/cygwin/Makefile.common"
.include "../../mk/bsd.pkg.mk"
