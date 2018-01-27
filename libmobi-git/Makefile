# $NetBSD$

PKGNAME=		libmobi-0.3
CATEGORIES=		textproc

GIT_REPOSITORIES=		libmobi
GIT_REPO.libmobi=		git://github.com/bfabiszewski/libmobi

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bfabiszewski/libmobi
COMMENT=	C library for handling Kindle (MOBI) formats of ebook documents
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libmobi

USE_LANGUAGES=	c

USE_TOOLS+=	automake aclocal autoheader autoconf
GNU_CONFIGURE=	yes

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

pre-configure:
	set -e; cd ${WRKSRC}; sh ./autogen.sh

do-install:
	set -e; cd ${WRKSRC}; ${MAKE} DESTDIR=${DESTDIR} install
.for f in ChangeLog README.md
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.endfor

.include "../../wip/mk/git-package.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
