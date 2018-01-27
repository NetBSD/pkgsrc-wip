# $NetBSD: Makefile,v 1.2 2015/08/19 21:02:45 wiedi Exp $
#

DISTNAME=	kibana-4.1.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=elasticsearch/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mbowie@rocketspace.com
HOMEPAGE=	http://www.elasticsearch.org/overview/kibana/
COMMENT=	Explore and visualize your data
LICENSE=	apache-2.0

DEPENDS+=	elasticsearch>=1.4.3:../../databases/elasticsearch
DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs
DEPENDS+=	git-[0-9]*:../../devel/git

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

EGDIR=		${PREFIX}/share/examples/kibana
KBDIR=		${PREFIX}/share/kibana
CONF_FILES=	${EGDIR}/kibana.yml ${PKG_SYSCONFDIR}/kibana.yml

RCD_SCRIPTS=	kibana
FILES_SUBST+=	KBDIR=${KBDIR}

INSTALLATION_DIRS+=	${KBDIR}
INSTALLATION_DIRS+=	${EGDIR}

do-build:
	cd ${WRKSRC} && \
	npm install grunt-cli bower && \
	npm install && \
	./node_modules/.bin/bower --allow-root --config.interactive=false install && \
	./node_modules/.bin/grunt build

do-install:
	${FIND} ${WRKSRC}/build/dist/kibana/src/node_modules \
		-type f -exec ${CHMOD} ${DOCMODE} {} \;
	cd ${WRKSRC}/build/dist/kibana && pax -rw . ${DESTDIR}/${KBDIR}
	${INSTALL_DATA} ${DESTDIR}/${KBDIR}/config/kibana.yml ${DESTDIR}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
