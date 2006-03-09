# $NetBSD: Makefile,v 1.5 2006/03/09 14:50:27 obache Exp $
#

DISTNAME=	pop-before-smtp-1.41
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=popbsmtp/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://popbsmtp.sourceforge.net/
COMMENT=	Simple daemon for pop-before-smtp

USE_LANGUAGES=	# empty
USE_PKGINSTALL=	yes
USE_TOOLS+=	perl:run pod2man
REPLACE_PERL+=	pop-before-smtp

DEPENDS+=	p5-Net-Netmask-[0-9]*:../../devel/p5-Net-Netmask
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

EGDIR=		${PREFIX}/share/examples/pop-before-smtp
CONF_FILES=	${EGDIR:Q}/pop-before-smtp-conf.pl ${PKG_SYSCONFDIR:Q}/pop-before-smtp-conf.pl
RCD_SCRIPTS=	pop-before-smtp
DOCS_DIR=	${PREFIX}/share/doc/pop-before-smtp

INSTALLATION_DIRS=${EGDIR:S|^${PREFIX}/||} ${DOCS_DIR:S|^${PREFIX}/||}

do-build:
	${POD2MAN} ${WRKSRC:Q}/pop-before-smtp > ${WRKSRC:Q}/pop-before-smtp.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/pop-before-smtp ${PREFIX:Q}/sbin
	${INSTALL_DATA} ${WRKSRC:Q}/pop-before-smtp-conf.pl \
		${EGDIR:Q}/pop-before-smtp-conf.pl
	${INSTALL_MAN} ${WRKSRC:Q}/pop-before-smtp.8 \
		${PREFIX:Q}/man/man8/pop-before-smtp.8
.for f in COPYING ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC:Q}/${f:Q} ${DOCS_DIR:Q}/${f:Q}
.endfor
.for f in README.QUICKSTART README.rootless-install popauth.m4
	${INSTALL_DATA} ${WRKSRC:Q}/contrib/${f:Q} ${DOCS_DIR}
.endfor

.include "../../mk/bsd.pkg.mk"
