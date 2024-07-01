import java.util.Arrays;

class Meeting
{
    public Integer start;
    public Integer end;
    public Integer position;

    public Meeting(Integer start, Integer end, Integer position)
    {
        this.start=start;
        this.end=end;
        this.position=position;
    }

    @Override
    public String toString() {
        return "Meeting [start=" + start + ", end=" + end + ", position=" + position + "]";
    }

    
}


public class NMeetingsInOneRooms {

    /*
     * There is one meeting room in a firm. There are n meetings in the form of
     * (start[i], end[i]) where start[i] is start time of meeting i and end[i] is
     * finish time of meeting i.
     * What is the maximum number of meetings that can be accommodated in the
     * meeting room when only one meeting can be held in the meeting room at a
     * particular time? Return the maximum number of meetings that can be held in
     * the meeting room.
     * 
     * 
     * 
     * Note: Start time of one chosen meeting can't be equal to the end time of the
     * other chosen meeting.
     */


    public static Meeting [] meetingsInit(int start[], int end[])
    {
        Meeting [] meetings = new Meeting[start.length];
        for(int i=0;i<end.length;i++)
        {
            meetings[i] = new Meeting(start[i], end[i], i+1);
        }
        return meetings;
    }
    
    public static void main(String[] args)
    {
        int [] start = {0,3,1,5,5,8}; // array that stores meeting start time
        int [] end = {5,4,2,9,7,9}; // array that stores meeting end time

        Meeting[] meetings  =  meetingsInit(start, end);
        //sorting in acending order in terms of meeting end time
        Arrays.sort(meetings,(m1,m2)->Integer.compare(m1.end, m2.end));

        //to store the meeting numbers
        int meetingNos[] = new int[meetings.length+1];
        int count=1,finishingTime=0;

        finishingTime=meetings[0].end;
        meetingNos[0]=meetings[0].position;
        for(int i=1;i<meetings.length;i++) //traverse through all the meetings
        {
            /*
             * if the start time of a given meeting is more than 
             * the current finishing time, execute the if statement
             */
            if(meetings[i].start>finishingTime) 
            {
                count++; //increasing the number of meetings
                finishingTime=meetings[i].end; // updating the finishing time
                meetingNos[i]=meetings[i].position; // adding the meeting number that is being done.
            }
        }




        // System.out.println(count); //printing the number of meetings
        for(int i=0;i<meetingNos.length;i++)
        {
            if(meetingNos[i]!=0)
            {
                System.out.println(meetingNos[i]);
            }
        }
    }
}
