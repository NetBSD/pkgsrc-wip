# $NetBSD: Makefile,v 1.1 2007/01/23 17:48:28 bsadewitz Exp $

PKGNAME=	Mesa-${MESA_VERSION}
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

CONFLICTS=	Mesa-glx-[0-9]*

USE_LANGUAGES=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
EXTRACT_ONLY=		# empty

do-patch:	# empty
do-install:	# empty

.include "Makefile.common"

# The ordering is important here as glut/buildlink3.mk sets the version
# of Mesa required.
.include "../../wip/glut/buildlink3.mk"
.include "../../wip/glu/buildlink3.mk"
.include "../../wip/MesaLib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
