# $NetBSD: Makefile,v 1.1.1.1 2003/10/26 18:35:45 marc Exp $
#

DISTNAME=		metatheme-0.9.7
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/metatheme/0.9/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Themes for GNOME 2

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_PERL=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../devel/libgnomeui/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
