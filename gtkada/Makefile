# $NetBSD: Makefile,v 1.14 2010/06/13 22:47:06 thomasklausner Exp $
#

DISTNAME=		GtkAda-2.2.1
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		http://libre.act-europe.fr/GtkAda/
EXTRACT_SUFX=		.tgz

MAINTAINER=		john@johnrshannon.com
HOMEPAGE=		https://libre.adacore.com/GtkAda/
COMMENT=		Ada95 graphical toolkit

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake autoconf
USE_AUTOCONF=		yes

.include "../../mk/bsd.prefs.mk"

# This package requires an Ada compiler. Two are available:
# 1) lang/gcc34-ada and 2) lang/gcc34 built with Ada option
# If USE_GCC_34=YES this package will use gcc34. Otherwise,
# it will use gcc34-ada
BUILD_DEFS=	USE_GCC_34
USE_GCC_34?=	NO

pre-configure:
	cd ${WRKSRC} && autoconf

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
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
