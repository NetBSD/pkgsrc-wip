# $NetBSD: Makefile,v 1.11 2012/11/05 02:37:55 othyro Exp $
#

DISTNAME=	spe-0.8.4.h-wx2.6.1.0
PKGNAME=	${DISTNAME:C/\.[a-z]+.*//}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python.berlios/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pythonide.stani.be/
COMMENT=	Python IDE with UML, PyChecker, Debugger, GUI design, Blender and more
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-checker-[0-9]*:../../devel/py-checker
WRKSRC=		${WRKDIR}/${DISTNAME:C/-[a-z]+.*//}
PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes

REPLACE_INTERPRETER+=	env
REPLACE.env.old=	/usr/bin/env
REPLACE.env.new=	${PYTHONBIN}
REPLACE_FILES.env=	_spe/SPE.py _spe/SPE_DEBUG.py


.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
