# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:42:40 jihbed Exp $
#

DISTNAME=	ThePEG-1.6.1
PKGNAME=	thepeg-1.6.1
CATEGORIES=	science
MASTER_SITES=	http://home.thep.lu.se/~leif/ThePEG/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://home.thep.lu.se/~leif/ThePEG/
COMMENT=	Toolkit for High Energy Physics Event Generation
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CHECK_PORTABILITY_SKIP= configure

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake perl
USE_GNU_READLINE= yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

.include "../../devel/readline/buildlink3.mk"
BUILDLINK_API_DEPENDS.gsl+=		gsl>=1.4
.include "../../math/gsl/buildlink3.mk"
.include "../../wip/hepmc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
