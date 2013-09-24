# $NetBSD: Makefile,v 1.1 2013/09/24 11:13:53 fhajny Exp $

DISTNAME=	sphinx3-0.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmusphinx/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://cmusphinx.sourceforge.net/
COMMENT=	CMU Speech Recognition engine frontend
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	sphinx3.pc.in

.include "../../wip/sphinxbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
