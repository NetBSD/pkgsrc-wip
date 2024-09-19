# $NetBSD: Makefile,v 1.1.1.1 2010/08/09 20:30:37 jihbed Exp $
#

.include "../../wip/py-traits/Makefile.version"

DISTNAME=	Traits-${TRAITS_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/}

HOMEPAGE=	http://code.enthought.com/projects/traits/
COMMENT=	Manifest typing and reactive programming for Python

.include "../../wip/py-traits/Makefile.common"

INSTALLATION_DIRS=	share/doc/py-traits

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/traitsdocreadme.txt \
						 ${DESTDIR}${PREFIX}/share/doc/py-traits
	${INSTALL_DATA} ${WRKSRC}/docs/Pydoh_T3UMdoc_HOWTO.txt \
						 ${DESTDIR}${PREFIX}/share/doc/py-traits
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf \
						 ${DESTDIR}${PREFIX}/share/doc/py-traits


BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
