# $NetBSD: Makefile,v 1.4 2008/02/28 13:25:22 bsadewitz Exp $

PKGNAME=	Mesa-${MESA_PKGVERSION}
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

CONFLICTS=	Mesa-glx-[0-9]*

USE_LANGUAGES=		# empty
NO_CHECKSUM=		yes
NO_BUILD=		yes
NO_CONFIGURE= 	 	yes
EXTRACT_ONLY=		# empty
PLIST_SRC=		# empty (meta-package)

do-patch:	# empty
do-install:	# empty

.include "Makefile.common"

# The ordering is important here as glut/buildlink3.mk sets the version
# of Mesa required.
.include "../../wip/glut/buildlink3.mk"
.include "../../wip/glu/buildlink3.mk"
.include "../../wip/MesaLib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
