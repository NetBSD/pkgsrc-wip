# $NetBSD: Makefile,v 1.1 2013/08/30 15:03:43 hfath Exp $
#

DISTNAME=	am-utils-6.2
CATEGORIES=	sysutils
#MASTER_SITES=	ftp://ftp.am-utils.org/pub/am-utils/

MAINTAINER=		hauke@NetBSD.org
HOMEPAGE=		http://www.am-utils.org/
COMMENT=		Berkeley automounter suite of utilities
LICENSE=		original-bsd

GIT_REPOSITORIES=	am-utils
GIT_REPO.am-utils=	git://git.fsl.cs.sunysb.edu/am-utils-6.2.git
GIT_MODULE.am-utils=	am-utils-6.2

USE_TOOLS+=		yacc lex perl:run automake gettext-m4
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

INFO_FILES=		yes

CONFIGURE_ARGS+=	--without-ldap
CONFIGURE_ARGS+=	--without-hesiod
CONFIGURE_ARGS+=	--without-ndbm

RCD_SCRIPTS=		amd

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS+=	${EGDIR} ${PKGDOCDIR} etc/amd

EXTRA_DOC_FILES=	COPYING FAQ ChangeLog BUGS AUTHORS \
                        README.attrcache README.autofs README.ldap \
                        README.osx README.y2k NEWS README INSTALL
EXAMPLE_CONF_FILES=	amd.conf lostaltmail.conf

pre-configure:
	( cd  ${WRKSRC} && ${SH} bootstrap )

post-install:
.for i in ${EXTRA_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PKGDOCDIR}
.endfor
.for i in ${EXAMPLE_CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/scripts/${i}-sample ${DESTDIR}${EGDIR}/${i}
.endfor

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
