# $NetBSD: Makefile,v 1.1.1.1 2003/04/13 08:25:30 jmmv Exp $

DISTNAME=	pts-0.20a
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pts/}

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://pts.sourceforge.net
COMMENT=	Perl TetriNET Server

DEPENDS+=	p5-Config-IniFiles>=2.20:../../devel/p5-Config-IniFiles

NO_BUILD=	YES
USE_BUILDLINK2= YES
REPLACE_PERL=	${WRKSRC}/pts.pl

DATADIR=	${PREFIX}/share/pts

do-install:
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA_DIR} ${DATADIR}/logs
	${INSTALL_DATA_DIR} ${DATADIR}/dstats
	${INSTALL_DATA_DIR} ${DATADIR}/locale

	for config_files in pts.ban pts.ini pts.motd \
			    pts.news pts.secure; do \
		${INSTALL_DATA} ${WRKSRC}/$$config_files \
				${DATADIR}/$$config_files; \
	done

	for locales in en.msg ja.msg; do \
		${INSTALL_DATA} ${WRKSRC}/locale/$$locales \
				${DATADIR}/locale/$$locales; \
	done

	${INSTALL_SCRIPT} ${WRKSRC}/pts.pl ${PREFIX}/sbin/pts
	${INSTALL_SCRIPT} ${FILESDIR}/pts ${PREFIX}/etc/rc.d/pts

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
