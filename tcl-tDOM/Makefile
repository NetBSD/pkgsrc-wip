# $NetBSD: Makefile,v 1.2 2011/12/26 22:42:22 mwilhelmy Exp $
#

DISTNAME=	tDOM-0.8.2
CATEGORIES=	textproc
MASTER_SITES=	http://github.com/downloads/tDOM/tdom/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://tdom.github.com/
COMMENT=	High performance XML data processing for Tcl
LICENSE=	mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c
#CONFIGURE_ARGS+=	--with-expat=yes

.include "../../lang/tcl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
