# $NetBSD: Makefile,v 1.3 2004/02/24 17:11:56 jmmv Exp $
#

DISTNAME=		GtkAda-2.2.1
CATEGORIES=		devel
MASTER_SITES=		http://libre.act-europe.fr/GtkAda/
EXTRACT_SUFX=		.tgz

MAINTAINER=		john@johnrshannon.com
HOMEPAGE=		http://libre.act-europe.fr/GtkAda/
COMMENT=		Ada95 graphical toolkit

BUILD_DEPENDS+=		gcc3-ada-[0-9]*:../../lang/gcc3-ada

export PATH=${LOCALBASE}/gcc-3.3.2/bin:${PATH}
USE_BUILDLINK3=         yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_AUTOCONF=           yes
USE_X11=                yes
GCC_REQD=		3.3
GCC3_C=			yes
GCC3_ADA=		yes

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
