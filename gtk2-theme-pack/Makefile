# $NetBSD: Makefile,v 1.7 2004/05/15 21:11:36 blef Exp $
#

DISTNAME=      	gtk2-theme-pack
PKGNAME=       	gtk2-theme-pack-0.1
WRKSRC=		${WRKDIR}
CATEGORIES=    	x11
MASTER_SITES=	http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/
DISTFILES=	GKT2-Quantumcurve.tar.gz \
		GTK2-6nome.tar.gz \
		GTK2-Angelistic.tar.gz \
		GTK2-AnotherBrushedMetal.tar.bz2 \
		GTK2-Aqua-Metal.tar.gz \
		GTK2-Aquesco-ThreeColour.tar.gz \
		GTK2-BlackIce.tar.gz \
		GTK2-Blackmarble.tar.gz \
		GTK2-Blackmarble2.tar.gz \
		GTK2-BlackmarbleMatrix.tar.gz \
		GTK2-Blue-Chrome.tar.gz \
		GTK2-BlueBubble.tar.gz \
		GTK2-BlueSmooth.tar.gz \
		GTK2-Clean-Curve.tar.gz \
		GTK2-CleanIce-Gorilla.tar.gz \
		GTK2-CleanIce-Vanilla.tar.gz \
		GTK2-CleanIceGorilla.tar.gz \
		GTK2-CleanOrangish.tar.gz \
		GTK2-CleanTangerineDream.tar.gz \
		GTK2-CoolGorilla-ish.tar.gz \
		GTK2-CoolGorilla.tar.bz2 \
		GTK2-CoolGorillaInTheMist.tar.gz \
		GTK2-Dirty-Ice.tar.gz \
		GTK2-Etria.org-blue.tar.bz2 \
		GTK2-Etria.org.tar.bz2 \
		GTK2-Etriacurve-Default-1.0.tar.gz \
		GTK2-FishingTheSky-04.tar.gz \
		GTK2-Fishpie-0.11.tar.gz \
		GTK2-Funklor-0.2.tar.gz \
		GTK2-Funky-Monkey.tar.gz \
		GTK2-GitM.tar.gz \
		GTK2-Glacier-2.3.tar.gz \
		GTK2-GnuBubble.tar.gz \
		GTK2-Gonx.tar.bz2 \
		GTK2-Gorilla-ish.tar.gz \
		GTK2-Greencurve.tar.gz \
		GTK2-H2O-Ruby-0.1.tar.gz \
		GTK2-H2O-default-2.0.tar.gz \
		GTK2-Ibs.tar.gz \
		GTK2-IceCube.tar.gz \
		GTK2-Latte.tar.bz2 \
       		GTK2-Lighthouse-H20.tar.gz \
		GTK2-LighthouseGreen.tar.gz \
		GTK2-LighthouseIDEA.tar.bz2 \
		GTK2-LighthouseWhite.tar.gz \
		GTK2-LimeBubble.tar.gz \
		GTK2-MardiGras.tar.bz2 \
		GTK2-MardiGrasDeux.tar.gz \
		GTK2-MistOkayish.tar.gz \
		GTK2-OutWorld.tar.gz \
		GTK2-Panther.tar.gz \
		GTK2-Peachy-Clean.tar.gz \
		GTK2-PrettyOkayish.tar.gz \
		GTK2-Prion.tar.gz \
		GTK2-Purty-Cleanish.tar.gz \
		GTK2-Raleigh.tar.gz \
		GTK2-Red-Onion-0.02.tar.gz \
		GTK2-Sea-Ice.tar.gz \
		GTK2-Silver.tar.gz \
		GTK2-Smooth-2000.tar.gz \
		GTK2-Smooth-Cool-Blue.tar.gz \
		GTK2-Smooth-EyeCandy.tar.gz \
		GTK2-Smooth-Funky-Monkey.tar.gz \
		GTK2-Smooth-LightYellow.tar.gz \
		GTK2-Smooth-Orangish.tar.gz \
		GTK2-Smooth-Peachy-Clean.tar.gz \
		GTK2-Smooth-Posh.tar.gz \
		GTK2-Smooth-Sea-Ice.tar.gz \
		GTK2-Smooth-Step.tar.gz \
		GTK2-Smooth-Tangerine-Dream.tar.gz \
		GTK2-Smooth-Velvet.tar.gz \
		GTK2-Smooth-Xess.tar.gz \
		GTK2-Snowdream.tar.gz \
		GTK2-Solaris-thin.tar.gz \
		GTK2-South-Side.tar.gz \
		GTK2-Sunhouse-0.1.tar.gz \
		GTK2-TheBlues.tar.gz \
		GTK2-ThinAndMild.tar.gz \
		GTK2-ThinBright2.tar.gz \
		GTK2-TransMetal.tar.gz \
		GTK2-Traspy-Nolines.tar.gz \
		GTK2-Traspy.tar.gz \
		GTK2-Variance-Default-0.1.tar.gz \
		GTK2-WarmGorilla.tar.gz \
		GTK2-Water-Luna.tar.gz \
		GTK2-WinXP-Blue.tar.gz \
		GTK2-WinXP-Silver.tar.gz \
		GTK2-WinterWonderland.tar.bz2 \
		GTK2-Wonderland-Blue-1.0.tar.gz \
		GTK2-Wonderland-Debian.tar.gz \
		GTK2-Wonderland-Green-1.0.tar.gz \
		GTK2-Wonderland-Okayish.tar.gz \
		GTK2-Xfce-wrevolution.tar.bz2 \
		GTK2-Yattacier.tar.gz \
		GTK2-Yattacier2.tar.gz \
		GTK2-eMaCs.tar.gz \
		GTK2-m8Blue.tar.gz \
		GTK2-m8darker-default-1.0.tar.gz \
		GTK2-outWorld.tar.gz \
		GTK2-red-onion.tar.gz \
		GTK2-yglacier.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Art for your GTK+ 2.x desktop

# TODO: buildlinks?
DEPENDS+=	gtk2-engines>=2.2.0nb6:../../x11/gtk2-engines
DEPENDS+=	gtk2-engines-bluecurve>=1.0:../../wip/gtk2-engines-bluecurve
DEPENDS+=	gtk2-engines-dwerg>=0.6:../../wip/gtk2-engines-dwerg
DEPENDS+=	gtk2-engines-flat>=2.0:../../wip/gtk2-engines-flat
DEPENDS+=	gtk2-engines-galaxy>=0:../../wip/gtk2-engines-galaxy
DEPENDS+=	gtk2-engines-industrial>=0:../../wip/gtk2-engines-industrial
DEPENDS+=	gtk2-engines-lighthouseblue>=0.4:../../wip/gtk2-engines-lighthouseblue
DEPENDS+=	gtk2-engines-magichicken>=1.0.2:../../wip/gtk2-engines-magichicken
DEPENDS+=	gtk2-engines-mist>=0.10:../../wip/gtk2-engines-mist
DEPENDS+=	gtk2-engines-smooth>=0.5.6:../../wip/gtk2-engines-smooth

NO_BUILD=      	# defined

# clean up a bit. remove .xvpics (GIMP and xv thumbnail directories) and
# backup files

do-configure:
	${FIND} ${WRKDIR} -name .xvpics -type d -print0 | ${XARGS} -t -0 ${RM} -r
	${FIND} ${WRKDIR} -name \*~ -type f -print0 | ${XARGS} -t -0 ${RM}
	${FIND} ${WRKDIR} -name \*.orig -type f -print0 | ${XARGS} -t -0 ${RM}

do-install:
	cd ${WRKDIR} && ${PAX} -rw -pe [A-Za-z]* ${PREFIX}/share/themes

.include "../../mk/bsd.pkg.mk"
