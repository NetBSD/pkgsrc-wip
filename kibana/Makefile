# $NetBSD: Makefile,v 1.1 2015/02/22 20:10:34 mbowie Exp $
#

PKGNAME=	kibana-${VERSION}
DISTNAME=	v${VERSION}
VERSION=	4.0.0
CATEGORIES=	databases
MASTER_SITES=	https://github.com/elasticsearch/kibana/archive/
FETCH_USING=	curl

MAINTAINER=	mbowie@rocketspace.com
HOMEPAGE=	http://www.elasticsearch.org/overview/kibana/
COMMENT=	Explore and visualize your data
LICENSE=	apache-2.0

DEPENDS+=	elasticsearch>=1.4.3:../../databases/elasticsearch
DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

# Cannot use until GIT_TAG is supported
#GIT_REPOSITORIES=	kibana
#GIT_MODULE.kibana=	kibana
#GIT_REPO.kibana=	https://github.com/elasticsearch/kibana.git
#GIT_TAG.kibana=		v4.0.0
#PKGSRC_SETENV=		GIT_SSL_NO_VERIFY=true

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
	# NODE_PATH setup doesn't appear to do what I'm hoping for
	mkdir ${WRKDIR}/.node
	cd ${WRKSRC} && ${SETENV} NODE_PATH=${WRKDIR}/.node && \
		npm install -g grunt-cli bower && \
		npm install && bower --allow-root install && \
		grunt build

do-install:
	cd ${WRKSRC}/build/dist/kibana && pax -rw . ${DESTDIR}/${KBDIR}
	${INSTALL_DATA} ${DESTDIR}/${KBDIR}/config/kibana.yml ${DESTDIR}/${EGDIR}

# Cannot use until GIT_TAG is supported
#.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
