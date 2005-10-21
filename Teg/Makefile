# $NetBSD: Makefile,v 1.1.1.1 2005/10/21 15:50:34 wrzymski Exp $

DISTNAME=		teg-0.11.1
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=teg/}

MAINTAINER=		wrzymski@gmail.com
HOMEPAGE=		http://teg.sourceforge.net/
COMMENT=		Round-based computer board game

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS+=	teg.schemas

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
