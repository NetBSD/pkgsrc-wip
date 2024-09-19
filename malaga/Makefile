# $NetBSD: Makefile,v 1.2 2015/09/14 10:02:33 leot1990 Exp $
#

DISTNAME=	malaga-7.12
CATEGORIES=	textproc
MASTER_SITES=	http://home.arcor.de/bjoern-beutel/malaga/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.arcor.de/bjoern-beutel/malaga/
COMMENT=	Grammar development and application for natural languages
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
INFO_FILES=	yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
