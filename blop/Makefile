# $NetBSD: Makefile,v 1.1.1.1 2009/02/09 19:06:25 othyro Exp $
#

DISTNAME=	blop-0.2.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blop.sourceforge.net/
COMMENT=	Bandlimited LADSPA Oscillator Plugins

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-ladspa-prefix=${BUILDLINK_PREFIX.ladspa}

.include "../../audio/ladspa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
