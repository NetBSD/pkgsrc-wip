# $NetBSD: Makefile,v 1.9 2012/10/05 13:52:03 asau Exp $
#

DISTNAME=	pop-before-smtp-1.42
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=popbsmtp/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://popbsmtp.sourceforge.net/
COMMENT=	Simple daemon for pop-before-smtp

USE_LANGUAGES=	# empty
USE_TOOLS+=	perl:run pod2man
REPLACE_PERL+=	pop-before-smtp

DEPENDS+=	p5-Net-Netmask-[0-9]*:../../devel/p5-Net-Netmask
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

EGDIR=		${PREFIX}/share/examples/pop-before-smtp
CONF_FILES=	${EGDIR}/pop-before-smtp-conf.pl ${PKG_SYSCONFDIR}/pop-before-smtp-conf.pl
RCD_SCRIPTS=	pop-before-smtp
DOCS_DIR=	${PREFIX}/share/doc/pop-before-smtp

INSTALLATION_DIRS=${EGDIR:S|^${PREFIX}/||} ${DOCS_DIR:S|^${PREFIX}/||}	\
		sbin ${PKGMANDIR}/man8

do-build:
	pod2man ${WRKSRC}/pop-before-smtp > ${WRKSRC}/pop-before-smtp.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pop-before-smtp ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/pop-before-smtp-conf.pl \
		${DESTDIR}${EGDIR}/pop-before-smtp-conf.pl
	${INSTALL_MAN} ${WRKSRC}/pop-before-smtp.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/pop-before-smtp.8
.for f in COPYING ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${f:Q} ${DESTDIR}${DOCS_DIR}/${f:Q}
.endfor
.for f in README.QUICKSTART README.rootless-install popauth.m4
	${INSTALL_DATA} ${WRKSRC}/contrib/${f:Q} ${DESTDIR}${DOCS_DIR}/${f:Q}
.endfor

.include "../../mk/bsd.pkg.mk"
