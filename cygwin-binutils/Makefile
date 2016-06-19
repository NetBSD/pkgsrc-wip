# $NetBSD: Makefile,v 1.5 2012/09/25 08:20:47 makoto Exp $
# $Id: Makefile,v 1.5 2012/09/25 08:20:47 makoto Exp $

DISTNAME=	binutils-2.21
PKGNAME=	cygwin-${DISTNAME:S/-src//}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2
LICENSE=	gnu-gpl-v2

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://www.cygwin.com/
COMMENT=	GNU binutils ported to Win32/Cygwin environment

GNU_CONFIGURE=		yes
USE_TOOLS+=		pax
INFO_FILES=		yes

post-install:
.for f in windres dllwrap
	${LN} -fs ${PREFIX}/bin/${CYGWIN_TARGET}-${f} \
                ${DESTDIR}${PREFIX}/${CYGWIN_TARGET}/bin/${f}
.endfor

.include "../../wip/cygwin/Makefile.common"
.include "../../mk/bsd.pkg.mk"
