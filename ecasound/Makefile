# $NetBSD: Makefile,v 1.6 2012/11/25 23:32:10 othyro Exp $
#

DISTNAME=		ecasound-2.4.1
CATEGORIES=		audio
MASTER_SITES=		http://ecasound.seul.org/download/
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ecasound.seul.org/
COMMENT=		Multitrack audio processor


USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_NCURSES=		yes # term.h, setupterm(), ...

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
