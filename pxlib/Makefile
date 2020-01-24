# $NetBSD: Makefile,v 1.12 2013/03/03 17:27:53 othyro Exp $
#

DISTNAME=	pxlib-0.6.5
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pxlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pxlib.sourceforge.net/
COMMENT=	C language library for reading Paradox database files
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	pxlib.pc.in
USE_LANGUAGES+=		c c++
USE_TOOLS+=		intltool msgfmt msgmerge perl xgettext
GNU_CONFIGURE=		yes

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/recode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
