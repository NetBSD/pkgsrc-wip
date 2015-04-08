# $NetBSD: Makefile,v 1.2 2015/04/08 23:14:47 krytarowski Exp $

DISTNAME=	gcolor2-0.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gcolor2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/gcolor2/files/gcolor2/0.4/
COMMENT=	Simple color selector
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl pkg-config

BUILD_DEPENDS+=	p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
