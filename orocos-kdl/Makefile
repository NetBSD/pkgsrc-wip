# $NetBSD$
#

DISTNAME=	orocos-kdl-1.3.1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=orocos/}
GITHUB_PROJECT=	orocos_kinematics_dynamics

MAINTAINER=	rumko@NetBSD.org
HOMEPAGE=	http://www.orocos.org/kdl
COMMENT=	Kinematics and Dynamics Library (KDL)
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}/orocos_kdl/

USE_LANGUAGES=		c c++
USE_CMAKE=		yes

#REPLACE_PYTHON+=	src/Tools/wiki2qhelp.py src/Tools/PythonToCPP.py src/Tools/githubstats.py src/Tools/updatefromcrowdin.py src/Tools/updatecrowdin.py src/Tools/updateppa.py

.include "../../math/eigen3/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
