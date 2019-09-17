# $NetBSD$

PKG_VERSION=	1.10.1.469
DISTNAME=	clojure-tools-${PKG_VERSION}
PKGNAME=	clojure-${PKG_VERSION}
CATEGORIES=	lang
MASTER_SITES=	https://download.clojure.org/install/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://clojure.org/
COMMENT=	Dynamic programming language that targets the Java VM
LICENSE=	epl-v1.0

NO_BUILD=	yes
USE_JAVA=	run
USE_JAVA2=	8
USE_TOOLS+=	bash

REPLACE_BASH+=	clj
REPLACE_BASH+=	clojure

INSTALLATION_DIRS=	bin \
			clojure \
			clojure/libexec \
			${PKGMANDIR}/man1

WRKSRC=	${WRKDIR}/clojure-tools

SUBST_CLASSES+=		java
SUBST_STAGE.java=	pre-configure
SUBST_FILES.java=	clojure
SUBST_SED.java=		-e 's,PREFIX,${PREFIX}/clojure,g'

DEPENDS+=	rlwrap-[0-9]*:../../misc/rlwrap

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.edn ${DESTDIR}${PREFIX}/clojure
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DESTDIR}${PREFIX}/clojure/libexec
	${INSTALL_MAN} ${WRKSRC}/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/clj ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/clojure ${DESTDIR}${PREFIX}/bin

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
