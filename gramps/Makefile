# $NetBSD: Makefile,v 1.2 2004/01/25 14:36:25 marc Exp $
#

DISTNAME=		gramps-0.9.5
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gramps/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://gramps.sourceforge.net/
COMMENT=	Genealogical Research and Analysis Management Programming System

DEPENDS+=	yelp>=2.2:../../misc/yelp

.if !exists(/usr/bin/msgconv)
BUILD_DEPENDS+=	gettext>=0.10.35nb1:../../devel/gettext
.endif

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
#BUILD_USES_MSGFMT=	yes

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
# i18n support with other versions appears to not work
PYTHON_VERSION_REQD=	23pth

# maybe Reportlab         Enable creation of PDF documents 
#                     http://www.reportlab.com

#   Python Imaging Library (PIL)
#                    Enable generation of thumbnails for images
#                    http://www.pythonware.com/products/pil
# WITHOUT either PIL or ImageMagick *YOU WILL NOT BE ABLE TO USE THUMBNAILS*

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../textproc/py-xml/buildlink2.mk"
.include "../../x11/py-gtk2/buildlink2.mk"
.include "../../x11/py-gnome2/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
