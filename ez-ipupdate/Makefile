# $NetBSD: Makefile,v 1.1.1.1 2005/06/27 14:25:25 ghen Exp $

DISTNAME=		ez-ipupdate-3.0.11b7
CATEGORIES=		net
MASTER_SITES=		http://www.ez-ipupdate.com/dist/

MAINTAINER=		geert.hendrickx@ua.ac.be
HOMEPAGE=		http://www.ez-ipupdate.com/
COMMENT=		Client to update dynamic DNS entries

GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

EGDIR=			${PREFIX}/share/examples/ez-ipupdate
RCD_SCRIPTS=		ez-ipupdate

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	"Correcting paths in example scripts."
SUBST_FILES.path=	example-*.conf example.conf
SUBST_SED.path=		-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.path=		-e "s|cache-file=/etc/|cache-file=${PKG_SYSCONFDIR}/|g"
SUBST_SED.path+=	-e "s|you can use \"killall -QUIT ez-ipupdate\" under linux|you can use \"pkill -QUIT ez-ipupdate\" under NetBSD|g"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	@for FILE in ${WRKSRC}/example-*.conf;		\
	do						\
		${INSTALL_DATA} $${FILE} ${EGDIR}/;	\
	done
	${INSTALL_DATA} ${WRKSRC}/example.conf ${EGDIR}/ez-ipupdate.conf

.include		"../../mk/bsd.pkg.mk"
