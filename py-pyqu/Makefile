# $NetBSD: Makefile,v 1.1.1.1 2010/05/13 12:41:29 jihbed Exp $
#

DISTNAME=	Pyqu-0.1
PKGNAME=	${PYPKGPREFIX}-pyqu-0.1
CATEGORIES=	misc
MASTER_SITES=	http://pyqu.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pyqu/
COMMENT=	PyQu is an extension module for Python to implement quantum algorithms
LICENSE=		gnu-gpl-v3

DEPENDS+=	libquantum>=0.2.4:../../misc/libquantum

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-libquantum-include=${LIBQUANTUM_PREFIX}/include

PYDISTUTILSPKG= yes

DOCDIR=	${PREFIX}/share/doc/py-pyqu

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}doc/*.pdf \
			${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/py-pyqu

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
