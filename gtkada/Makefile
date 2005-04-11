# $NetBSD: Makefile,v 1.5 2005/04/11 21:12:41 tvierling Exp $
#

DISTNAME=		GtkAda-2.2.1
CATEGORIES=		devel
MASTER_SITES=		http://libre.act-europe.fr/GtkAda/
EXTRACT_SUFX=		.tgz

MAINTAINER=		john@johnrshannon.com
HOMEPAGE=		http://libre.act-europe.fr/GtkAda/
COMMENT=		Ada95 graphical toolkit

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_AUTOCONF=		yes
USE_X11=		yes

.include "../../mk/bsd.prefs.mk"

# This package requires an Ada compiler. Two are available:
# 1) lang/gcc34-ada and 2) lang/gcc34 built with Ada option
# If USE_GCC_34=YES this package will use gcc34. Otherwise,
# it will use gcc34-ada
BUILD_DEFS=	USE_GCC_34
USE_GCC_34?=	NO

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}
.if !empty(USE_GCC_34:M[Yy][Ee][Ss])
.  include "../../lang/gcc34/preconfigure.mk"
.else
.  include "../../lang/gcc34-ada/preconfigure.mk"
.endif

.if !empty(USE_GCC_34:M[Yy][Ee][Ss])
.  include "../../lang/gcc34/buildlink3.mk"
.else
.  include "../../lang/gcc34-ada/buildlink3.mk"
.endif
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
